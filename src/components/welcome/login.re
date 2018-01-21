let component = ReasonReact.statelessComponent("Login");

let make = _children => {
  ...component,
  render: _self => <div> <h2> (Utils.str("LOGIN")) </h2> <LoginButton /> </div>
};