[@bs.module "reactstrap"] external reactClass : ReasonReact.reactClass = "Row";

let bool_of_opt = opt =>
  switch opt {
  | None => false
  | Some(false) => false
  | Some(true) => true
  };

let make = (~className="", ~noGutters=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "className": className,
      "noGutters": noGutters |> bool_of_opt |> Js.Boolean.to_js_boolean
    },
    children
  );