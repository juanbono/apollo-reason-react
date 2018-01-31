[@bs.module "reactstrap"]
external reactClass : ReasonReact.reactClass = "Form";

/* TODO: Test it*/
let make = (~inline=?, ~tag="form", ~className="", children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "inline": inline |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "tag": tag,
      "className": className
    },
    children
  );