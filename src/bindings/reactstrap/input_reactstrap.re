[@bs.module "reactstrap"]
external reactClass : ReasonReact.reactClass = "Input";

let make =
    (
      ~type_="text",
      ~size=?,
      ~bsSize=?,
      ~valid=?,
      ~tag="p",
      ~innerRef=?,
      ~plaintext=?,
      ~className="",
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "type": type_,
      "className": className,
      "tag": tag,
      "valid": valid |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "innerRef": innerRef |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "size": size |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "bsSize": bsSize |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "plaintext": plaintext |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean
    },
    children
  );