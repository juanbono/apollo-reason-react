/* TODO */
let reducer = (action: Types.UserState.action, state: Types.AppState.state) =>
  switch action {
  | UpdateCurrentUser => ReasonReact.Update(state)
  };