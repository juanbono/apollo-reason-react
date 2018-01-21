Utils.requireCSS("./index.css");

ReactDOMRe.renderToElementWithId(<App />, "root");

switch [%external window] {
| None => ()
| Some((window: Dom.window)) =>
  Utils.dispatchEvent(window, Utils.makeEvent(`popstate))
};