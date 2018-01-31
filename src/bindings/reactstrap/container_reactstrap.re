[@bs.module "reactstrap"]
external reactClass : ReasonReact.reactClass = "Container";

let make = (~id="", ~className="", ~fluid=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "id": id,
      "className": className,
      "fluid": fluid |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean
    },
    children
  );