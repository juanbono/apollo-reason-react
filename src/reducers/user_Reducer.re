/* TODO */
module U = Types.User;

module A = Types.App;

let reduce = (action: U.action, state: A.state) =>
  switch action {
  | UpdateUser => ReasonReact.Update(state)
  | NoUser => ReasonReact.NoUpdate
  };