/** Creates a React element from a string */
let str = ReasonReact.stringToElement;

let (<|) = (f, g, x) => f(g(x));

/** Require css file, for side effect only (it doesn't return a string) */
[@bs.val]
external requireCSS : string => unit = "require";

/** Require an asset (eg. an image) and return exported string value (image URI) */
[@bs.val]
external requireAssetURI : string => string = "require";

[@bs.send] external dispatchEvent : (Dom.window, Dom.event) => unit = "";

[@bs.new]
external makeEvent : ([@bs.string] [ | `popstate]) => Dom.event = "Event";

type queryString = (Js.String.t, Js.String.t);

let query_of_array = arr =>
  switch (Array.to_list(arr)) {
  | [n, v] => (n, v)
  | _ => ("", "")
  };

let string_of_query = ((fieldName, fieldValue)) => {
  let name = fieldName == "" ? "<nothing>" : fieldName;
  let value = fieldValue == "" ? "<nothing>" : fieldValue;
  {j|$(name): $(value)|j};
};

let parseQueryString = s =>
  s |> Js.String.split("&") |> Array.map(Js.String.split("="));

type authInfo = {
  auth_token: string,
  client_id: string,
  uid: string
};

let rec any = (listOfPredicates, a) =>
  switch listOfPredicates {
  | [] => false
  | [p, ...ps] => p(a) || any(ps, a)
  };

let rec all = (listOfPredicates, a) =>
  switch listOfPredicates {
  | [] => true
  | [p, ...ps] => p(a) && all(ps, a)
  };

let filterRequiredFields = lst => {
  open List;
  let reqs = [
    mem_assoc("uid"),
    mem_assoc("client_id"),
    mem_assoc("auth_token")
  ];
  let hasFields = x => all(reqs, x);
  if (hasFields(lst)) {
    Some({
      auth_token: lst |> assoc("auth_token"),
      client_id: lst |> assoc("client_id"),
      uid: lst |> assoc("uid")
    });
  } else {
    None;
  };
};

let extractQuerystring = querystring =>
  parseQueryString(querystring)
  |> Array.map(query_of_array)
  |> Array.to_list
  |> filterRequiredFields;

module Option = {
  let unwrapUnsafely = data =>
    switch data {
    | Some(v) => v
    | None => raise(Invalid_argument("unwrapUnsafely called on None"))
    };
};