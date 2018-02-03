open Utils;

requireCSS("bootstrap/dist/css/bootstrap.css");

module Router = ReasonReact.Router;

module RouterT = Types.Router;

module AppT = Types.App;

module UserT = Types.User;

type state = AppT.state;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => AppT.initialState,
  reducer: (action: AppT.action, state: state) =>
    switch action {
    | RouterAction(action) => Reducer.Router.reduce(action, state)
    | UserAction(action) => Reducer.User.reduce(action, state)
    },
  subscriptions: self => [Reducer.Router.subscription(self)],
  render: self => (AppT.getCurrentPage(self.state))
};