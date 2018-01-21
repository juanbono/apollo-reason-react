open Utils;

requireCSS("./app.css");

module Router = ReasonReact.Router;

module RouterT = Types.Router;

module AppStateT = Types.AppState;

module UserStateT = Types.UserState;

type state = Types.AppState.state;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => AppStateT.initialState,
  reducer: (action: AppStateT.action, state: state) =>
    switch action {
    | RouterAction(action) => Routing.reducer(action, state)
    | UserStateAction(action) => UserState.reducer(action, state)
    },
  subscriptions: self => [Routing.routerSub(self)],
  render: self =>
    <div className="App">
      <div className="App-header"> <h2> (str("Bienvenido")) </h2> </div>
      <p className="App-intro" />
      <h2> (str("Ruta Actual")) </h2>
      <p> (str("Ruta: " ++ AppStateT.getUrl(self.state))) </p>
      <button onClick=(_e => Router.push("/"))> (str("Welcome")) </button>
      <button onClick=(_e => Router.push("registration"))>
        (str("Registration"))
      </button>
      <button onClick=(_e => Router.push("home"))> (str("Home")) </button>
      (AppStateT.getCurrentPage(self.state))
    </div>
};