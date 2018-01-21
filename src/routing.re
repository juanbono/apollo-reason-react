module R = Types.Router;

module A = Types.AppState;

let reducer = (action: R.action, state: A.state) =>
  switch action {
  | R.ShowWelcome =>
    ReasonReact.Update({
      ...state,
      routerState: R.updateRouterState(<Login />, ShowWelcome)
    })
  | R.ShowHome =>
    ReasonReact.Update({
      ...state,
      routerState: R.updateRouterState(<Home />, ShowHome)
    })
  | R.ShowRegistration =>
    ReasonReact.Update({
      ...state,
      routerState: R.updateRouterState(<Registration />, ShowRegistration)
    })
  | R.ShowAuthPage(creds) =>
    ReasonReact.Update({
      ...state,
      routerState:
        R.updateRouterState(
          <Auth
            credentials=(Some(creds))
            onReceive=(
              x =>
                Js.log2(
                  "user received",
                  Js.Dict.get(x, "username") |> Utils.Option.unwrapUnsafely
                )
            )
          />,
          ShowAuthPage(creds)
        )
    })
  };

let routerSub = component =>
  ReasonReact.(
    Sub(
      () =>
        Router.watchUrl(url =>
          switch url.path {
          | ["home"] => component.send(A.RouterAction(R.ShowHome))
          | ["registration"] =>
            component.send(A.RouterAction(R.ShowRegistration))
          | ["auth"] =>
            open Utils;
            let qs =
              parseQueryString(url.search)
              |> Array.map(query_of_array)
              |> Array.to_list;
            switch (filterRequiredFields(qs)) {
            | None => component.send(A.RouterAction(R.ShowWelcome))
            | Some(credentials) =>
              component.send(A.RouterAction(R.ShowAuthPage(credentials)))
            };
          | _ => component.send(A.RouterAction(R.ShowWelcome))
          }
        ),
      Router.unwatchUrl
    )
  );