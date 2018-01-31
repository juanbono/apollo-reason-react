[@bs.module "reactstrap"] external reactClass : ReasonReact.reactClass = "Col";

let make = (~xs=?, ~sm=?, ~md=?, ~lg=?, ~xl=?, ~widths=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "xs": xs,
      "sm": sm,
      "md": md,
      "lg": lg,
      "xl": xl,
      "widths": widths
    },
    children
  );