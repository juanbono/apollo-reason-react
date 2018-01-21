module type Type = {
  type state;
  type action;
  let string_of_action: action => string;
};

module UserState = {
  type action =
    | UpdateCurrentUser;
  type state =
    | Nothing;
  let string_of_action = action =>
    switch action {
    | UpdateCurrentUser => "UpdateCurrentUser action"
    };
};

module Router = {
  type state = {
    currentPage: ReasonReact.reactElement,
    url: string
  };
  type action =
    | ShowWelcome
    | ShowHome
    | ShowRegistration
    | ShowAuthPage(Utils.authInfo);
  let string_of_action = action =>
    switch action {
    | ShowWelcome => "/"
    | ShowHome => "home"
    | ShowRegistration => "registration"
    | ShowAuthPage(_) => "auth"
    };
  let updateRouterState = (component, action) => {
    currentPage: component,
    url: string_of_action(action)
  };
};

module AppState = {
  type action =
    | RouterAction(Router.action)
    | UserStateAction(UserState.action);
  type state = {
    userState: UserState.state,
    routerState: Router.state
  };
  let string_of_action = action =>
    switch action {
    | RouterAction(a) => "RouterAction " ++ Router.string_of_action(a)
    | UserStateAction(a) => "UserStateAction " ++ UserState.string_of_action(a)
    };
  let initialState = {
    userState: UserState.Nothing,
    routerState: {
      currentPage: <Login />,
      url: Router.string_of_action(Router.ShowWelcome)
    }
  };
  let getCurrentPage = state => state.routerState.currentPage;
  let getUrl = state => state.routerState.url;
};