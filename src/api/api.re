open Fetch;

open Utils;

let baseUrl = "https://apollo-core.herokuapp.com/";

let mkHeaders = authInfo =>
  HeadersInit.make({
    "Content-Type": "application/json",
    "Access-Token": authInfo.auth_token,
    "Client": authInfo.client_id,
    "UID": authInfo.uid
  });

let mkReq = (maybeCreds: option(authInfo), method, url) =>
  switch maybeCreds {
  | None => RequestInit.make(~method_=method, ()) |> fetchWithInit(url)
  | Some(authInfo) =>
    RequestInit.make(~method_=method, ~headers=mkHeaders(authInfo), ())
    |> fetchWithInit(url)
  };

module Users = {
  let callback_url = "http://localhost:3000/auth";
  let authPrefix = baseUrl ++ "auth/";
  /** Publico */
  let authUrl = {j|$(authPrefix)google_oauth2?auth_origin_url=$(callback_url)|j};
  /** Usuario */
  let validate_token = {j|$(authPrefix)validate_token|j};
  let getByID = authInfo => {
    let id = authInfo.uid;
    Js.Promise.(
      {j|$(baseUrl)users/$(id)|j}
      |> mkReq(Some(authInfo), Get)
      |> then_(Response.json)
      |> then_(json => Js.Json.decodeArray(json) |> resolve)
      |> then_(opt => Option.unwrapUnsafely(opt) |> resolve)
      |> then_(json => Js.log(json) |> resolve)
    );
  };
  let getByUsername = (authInfo, username) =>
    Js.Promise.(
      {j|$(baseUrl)users/$(username)|j}
      |> mkReq(Some(authInfo), Get)
      |> then_(Response.json)
      |> then_(json => Js.Json.decodeObject(json) |> resolve)
      |> then_(opt => Option.unwrapUnsafely(opt) |> resolve)
    );
  let getCurrentUser = authInfo =>
    Js.Promise.(
      {j|$(baseUrl)users/me|j}
      |> mkReq(Some(authInfo), Get)
      |> then_(Response.json)
      |> then_(json => Js.Json.decodeObject(json) |> resolve)
      |> then_(opt => Option.unwrapUnsafely(opt) |> resolve)
    );
  let updateUser = /* PUT */ {j|$(baseUrl)users/me|j};
  let validateUser = /* POST */ {j|$(baseUrl)users/me/validate|j};
  let updateImage = /* PUT */ {j|$(baseUrl)users/me/image|j};
  let getTravels = id => /* GET */ {j|$(baseUrl)$(id)/travels|j};
  let getPosts = id => /* GET */ {j|$(baseUrl)$(id)/posts|j};
  let getFavorites = id => /* GET */ {j|$(baseUrl)$(id)/favorites|j};
  let getFollowings = id => /* GET */ {j|$(baseUrl)$(id)/followings|j};
  let getFollowers = id => /* GET */ {j|$(baseUrl)$(id)/followers|j};
  let follow = id => /* POST */ {j|$(baseUrl)$(id)/followers|j};
  let stopFollowing = id => /* DELETE */ {j|$(baseUrl)$(id)/followers|j};
  let getAuthorizations = /* GET */ {j|$(baseUrl)users/me/authorizations|j};
  /* TODO: search: list(terms) => option(user) */
};

module Publications = {
  let getAll = /* GET */ {j|$(baseUrl)home|j};
};

module Notifications = {
  let prefix = {j|$(baseUrl)notifications|j};
  let getAll = /* GET */ prefix;
  let getNotRead = /* GET */ {j|$(prefix)?readed=false|j};
  let setRead = /* POST */ {j|$(prefix)/read|j};
};

module Comments = {
  let getById = commentId => /* GET */ {j|$(baseUrl)comments/$(commentId)|j};
  /* TODO: search: list(terms) => option(comment) */
};

module Travels = {
  let prefix = {j|$(baseUrl)travels|j};
  let createPublic = /* POST */ prefix;
  let createPrivate = /* POST */ prefix;
  let delete = travelId => /* DELETE */ {j|$(prefix)/$(travelId)|j};
  let getById = travelId => /* GET */ {j|$(prefix)/$(travelId)|j};
  let getFavorites = travelId =>
    /* GET */ {j|$(prefix)/$(travelId)/favorites|j};
  let setFavorite = travelId =>
    /* POST */ {j|$(prefix)/$(travelId)/favorites|j};
  let unsetFavorite = travelId =>
    /* DELETE */ {j|$(prefix)/$(travelId)/favorites|j};
  let getComments = travelId => /* GET */ {j|$(prefix)/$(travelId)/comments|j};
  let comment = travelId => /* POST */ {j|$(prefix)/$(travelId)/comments|j};
  let getAuthorizations = travelId =>
    /* GET */ {j|$(prefix)/$(travelId)/authorizations|j};
  /* TODO: search: list(terms) => option(travel) */
};