module Auth = {
  type t = Utils.authInfo;
  type action =
    | UpdateAuthInfo(t)
    | ResetAuthInfo;
  type state =
    | AuthInfo(t)
    | NoAuthInfo;
};

module User = {
  type action =
    | UpdateUser
    | NoUser;
  type state =
    | Nothing;
};

module Router = {
  type state = {
    currentPage: ReasonReact.reactElement,
    url: string
  };
  type action =
    | ShowWelcome
    | ShowHome
    | ShowSignUp(Utils.authInfo)
    | ShowAuthPage(Utils.authInfo);
  let string_of_action = action =>
    switch action {
    | ShowWelcome => "/"
    | ShowHome => "home"
    | ShowSignUp(_) => "signup"
    | ShowAuthPage(_) => "auth"
    };
  let updateRouterState = (component, action) => {
    currentPage: component,
    url: string_of_action(action)
  };
};

module App = {
  type action =
    | RouterAction(Router.action)
    | UserAction(User.action);
  type state = {
    userState: User.state,
    routerState: Router.state,
    authState: Auth.state
  };
  let initialState = {
    userState: User.Nothing,
    routerState: {
      currentPage: <Welcome />,
      url: Router.string_of_action(Router.ShowWelcome)
    },
    authState: Auth.NoAuthInfo
  };
  let getCurrentPage = state => state.routerState.currentPage;
  let getUrl = state => state.routerState.url;
  let getCurrentUser = state => state.userState;
  let getUserAuthInfo = state => state.authState;
};