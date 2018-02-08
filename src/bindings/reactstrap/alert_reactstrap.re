[@bs.module "reactstrap"]
external reactClass : ReasonReact.reactClass = "Alert";

let make =
    (
      ~className="",
      ~closeClassName="",
      ~color="success",
      ~isOpen=true,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "className": className,
      "closeClassName": closeClassName,
      "color": color,
      "isOpen": isOpen
    },
    children
  );