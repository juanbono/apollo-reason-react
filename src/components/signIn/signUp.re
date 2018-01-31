module SignUpFormParams = {
  /*
   Campos y validaciones:
   - nombre: [V.required, V.minLength(1), V.maxLength(20)]
   - apellido: [V.required, V.minLength(1), V.maxLength(20)]
   - username: [V.required, V.minLength(4), V.maxLength(20)]
   - descripcion: V.maxLength(150)
    */
  type state = {
    firstname: string,
    lastname: string,
    username: string,
    description: string
  };
  /* Defined the field types, used for validation and change handling */
  type fields = [ | `firstname | `lastname | `username | `description];
  /* Now teach ReForm how to get and set your fields given the types */
  /* The syntax goes (field, getter, setter) */
  let lens = [
    (`firstname, s => s.firstname, (s, firstname) => {...s, firstname}),
    (`lastname, s => s.lastname, (s, lastname) => {...s, lastname}),
    (`username, s => s.username, (s, username) => {...s, username}),
    (`description, s => s.description, (s, description) => {...s, description})
  ];
};

module SignUpFormContainer = ReForm.Create(SignUpFormParams);

let defaults = (defaultValue, optional) =>
  switch optional {
  | Some(value) => value
  | None => defaultValue
  };

open Reactstrap;

let component = ReasonReact.statelessComponent("SignUp");

let make = _children => {
  ...component,
  render: _self =>
    <Form>
      <FormGroup>
        <Reactstrap.Label> ("Nombre" |> Utils.str) </Reactstrap.Label>
      </FormGroup>
    </Form>
};