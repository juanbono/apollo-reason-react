[@bs.module "react-google-login-component"]
external reactClass : ReasonReact.reactClass = "GoogleLogin";

/* Usage example:
    <GoogleLogin
      socialId="763211937031-vlpfscc6uf66cq8lcvu909hu8hnv15gr.apps.googleusercontent.com"
      className="login-button"
      scope="profile"
      fetchBasicProfile=true
      responseHandler=handler
      buttonText="Login"
    />
   */
let make =
    (
      ~socialId: string,
      ~className: string,
      ~scope: string,
      ~fetchBasicProfile: bool,
      ~responseHandler: 'a => unit,
      ~buttonText: string,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "socialId": socialId,
      "className": className,
      "scope": scope,
      "fetchBasicProfile": Js.Boolean.to_js_boolean(fetchBasicProfile),
      "responseHandler": responseHandler,
      "buttonText": buttonText
    },
    children
  );