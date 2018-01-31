let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <Reactstrap.Container fluid=true>
      <h1> ("Home Component" |> Utils.str) </h1>
      <Reactstrap.Row> ("Fila 1" |> Utils.str) </Reactstrap.Row>
      <Reactstrap.Row> ("Fila 2" |> Utils.str) </Reactstrap.Row>
      <Reactstrap.Row> ("Fila 3" |> Utils.str) </Reactstrap.Row>
    </Reactstrap.Container>
};