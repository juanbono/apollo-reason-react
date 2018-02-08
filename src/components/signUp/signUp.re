open Utils;

module V = Val;

module P = V.SignUpFormParams;

module H = ReForm.Helpers;

module SignUpFormContainer = ReForm.Create(V.SignUpFormParams);

let defaults = (defaultValue, optional) =>
  switch optional {
  | Some(value) => value
  | None => defaultValue
  };

let custom = f => ReForm.Validation.Custom(f);

open Reactstrap;

/* A pattern we are using to ease the reading of function as children */
let enhancer = (creds, mapper) =>
  ReForm.Validation.(
    <SignUpFormContainer
      onSubmit=(
        /* Enviar los datos del formulario al backend */
        (values, ~setSubmitting as _, ~setError as _) => {
          Api.Users.updateUser(creds, values) |> ignore;
          Js.log(values);
        }
      )
      initialState={firstname: "", lastname: "", username: "", description: ""}
      schema=[
        (
          `firstname,
          Custom(
            s =>
              V.(
                mkVal(
                  between(1, 20, s.lastname) && required(s.lastname),
                  "Falta nombre"
                )
              )
          )
        ),
        (
          `lastname,
          Custom(
            s =>
              V.(
                mkVal(
                  between(1, 20, s.lastname) && required(s.lastname),
                  "Falta el apellido"
                )
              )
          )
        ),
        (`username, Required),
        (`description, Required)
      ]>
      ...mapper
    </SignUpFormContainer>
  );

let component = ReasonReact.statelessComponent("SignUp");

let make = (~credentials, _children) => {
  ...component,
  render: _self =>
    enhancer(
      credentials, ({form, handleChange, handleSubmit, getErrorForField, _}) =>
      <form>
        <label> <span> ("Nombre:" |> str) </span> </label>
        <input
          value=form.values.firstname
          onChange=(H.handleDomFormChange(handleChange(`firstname)))
        />
        <Alert color="danger">
          (getErrorForField(`firstname) |> defaults("") |> str)
        </Alert>
        <label> <span> ("Apellido:" |> str) </span> </label>
        <input
          value=form.values.lastname
          onChange=(H.handleDomFormChange(handleChange(`lastname)))
        />
        <p> (getErrorForField(`lastname) |> defaults("") |> str) </p>
        <label> <span> ("Nombre de Usuario:" |> str) </span> </label>
        <input
          value=form.values.username
          onChange=(H.handleDomFormChange(handleChange(`username)))
        />
        <p> (getErrorForField(`username) |> defaults("") |> str) </p>
        <label> <span> ("Descripcion:" |> str) </span> </label>
        <input
          value=form.values.description
          onChange=(H.handleDomFormChange(handleChange(`description)))
        />
        <p> (getErrorForField(`description) |> defaults("") |> str) </p>
        <button
          _type="submit"
          onSubmit=(
            event => {
              ReactEventRe.Synthetic.preventDefault(event);
              handleSubmit();
            }
          )>
          ("Submit" |> str)
        </button>
      </form>
    )
};