let between = (min, max, s) =>
  String.length(s) < min || String.length(s) > max;

let required = s => Js.String.length(s) != 0;

let mkVal = (cond, msg) => cond ? Some(msg) : None;

module SignUpFormParams = {
  /*
   Campos y validaciones:
   - nombre: [V.required, V.minLength(1), V.maxLength(20)]    OK!
   - apellido: [V.required, V.minLength(1), V.maxLength(20)]  OK!
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

let lastname = (s: SignUpFormParams.state) => s.lastname;

let firstname = (s: SignUpFormParams.state) => s.firstname;

let username = (s: SignUpFormParams.state) => s.username;

let description = (s: SignUpFormParams.state) => s.description;