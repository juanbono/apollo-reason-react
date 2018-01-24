Utils.requireCSS("./index.css");

ReactDOMRe.renderToElementWithId(<App />, "root");

/* Trigger the subscription handler when the
   user searches using the navigation bar */
switch [%external window] {
| None => ()
| Some((window: Dom.window)) =>
  Utils.dispatchEvent(window, Utils.makeEvent(`popstate))
};