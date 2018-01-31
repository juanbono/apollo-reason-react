[@bs.module "reactstrap"]
external reactClass : ReasonReact.reactClass = "FormGroup";

let make =
    (
      ~row=?,
      ~check=?,
      ~inline=?,
      ~disabled=?,
      ~tag="div",
      ~className="",
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "row": row |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "check": check |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "inline": inline |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "disabled": disabled |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "tag": tag,
      "className": className
    },
    children
  );