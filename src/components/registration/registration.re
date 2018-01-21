let component = ReasonReact.statelessComponent("Registration");

let make = _children => {
  ...component,
  render: _self => <h1> (Utils.str("Registration Component")) </h1>
};