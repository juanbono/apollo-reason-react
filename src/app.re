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
    | RouterAction(action) => Routing.reducer(action, state)
    | UserAction(action) => UserState.reducer(action, state)
    },
  subscriptions: self => [Routing.routerSub(self)],
  render: self =>
    <div className="App"> (AppT.getCurrentPage(self.state)) </div>
};