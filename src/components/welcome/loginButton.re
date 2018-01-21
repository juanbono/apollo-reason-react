let component = ReasonReact.statelessComponent("loginButton");

let make = _children => {
  ...component,
  render: _self =>
    <button
      onClick=(
        _event => DomRe.Window.setLocation(DomRe.window, Api.Users.authUrl)
      )>
      (Utils.str("Login"))
    </button>
};