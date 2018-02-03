let component = ReasonReact.statelessComponent("loginButton");

let make = _children => {
  ...component,
  render: _self =>
    /* <button
      onClick=(_e => DomRe.Window.setLocation(DomRe.window, Api.Users.authUrl))>
      <GoogleIcon />
    </button> */
    <a href=(Api.Users.authUrl)> <GoogleIcon /> </a>
};