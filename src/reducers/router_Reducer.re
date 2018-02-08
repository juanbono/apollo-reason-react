module R = Types.Router;

module A = Types.App;

let updateState = (state: A.state, component, action) =>
  ReasonReact.Update({
    ...state, /* leave user state unchanged and only modify the router state */
    routerState: R.updateRouterState(component, action)
  });

let reduce = (action: R.action, state: A.state) =>
  switch action {
  | ShowWelcome => updateState(state, <Welcome />, ShowWelcome)
  | ShowHome => updateState(state, <Home />, ShowHome)
  | ShowSignUp(creds) =>
    updateState(state, <SignUp credentials=creds />, ShowSignUp(creds))
  | ShowAuthPage(creds) =>
    let f = u =>
      Js.log(Js.Dict.get(u, "username") |> Utils.Option.unwrapUnsafely);
    let comp = <AuthPage credentials=(Some(creds)) onReceive=f />;
    updateState(state, comp, ShowAuthPage(creds));
  };

let subscription = component =>
  ReasonReact.(
    Sub(
      () =>
        Router.watchUrl(url =>
          switch url.path {
          | ["home"] => component.send(A.RouterAction(ShowHome))
          | ["signup"] =>
            switch (component.state |> A.getUserAuthInfo) {
            | NoAuthInfo => component.send(A.RouterAction(ShowWelcome))
            | AuthInfo(a) => component.send(A.RouterAction(ShowSignUp(a)))
            }
          | ["auth"] =>
            switch (Utils.extractQuerystring(url.search)) {
            | None => component.send(A.RouterAction(ShowWelcome))
            | Some(a) => component.send(A.RouterAction(ShowAuthPage(a)))
            }
          | _ => component.send(A.RouterAction(ShowWelcome))
          }
        ),
      Router.unwatchUrl
    )
  );