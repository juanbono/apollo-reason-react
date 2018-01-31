open Utils;

let component = ReasonReact.statelessComponent("TeamIcon");

type member = {
  img: string,
  linkedin: string
};

let make = (~member, ~linkedin, _children) => {
  ...component,
  render: _self =>
    <div className="equipo">
      <a href=linkedin> <img className="equipo-img" src=member /> </a>
    </div>
};