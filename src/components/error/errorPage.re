/* We should make this component parametric on the type of error, something like:
   let make = (typeOfError, children) => {
     ...component,
     render: self => {
       ... do something with the type of error
     }
   }

   */
let component = ReasonReact.statelessComponent("Error");

let make = _children => {
  ...component,
  render: _self => ReasonReact.nullElement
};