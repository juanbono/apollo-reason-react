type shape = {
  size: string,
  order: string,
  offset: string
};

type columnProps =
  | String(string)
  | Number(float)
  | Shape(shape);

let colWidths = ["xs", "sm", "md", "lg", "xl"];

[@bs.module "reactstrap"]
external reactClass : ReasonReact.reactClass = "Label";

let make =
    (
      ~className="",
      ~hidden=?,
      ~check=?,
      ~tag="label",
      ~xs=?,
      ~sm=?,
      ~md=?,
      ~lg=?,
      ~xl=?,
      ~widths=colWidths,
      ~size=?,
      ~for_=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "className": className,
      "hidden": hidden |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "check": check |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "tag": tag,
      "xs": xs |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "sm": sm |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "md": md |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "lg": lg |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "xl": xl |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "size": size |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean,
      "widths": widths,
      "for": for_ |> Utils.bool_of_opt |> Js.Boolean.to_js_boolean
    },
    children
  );