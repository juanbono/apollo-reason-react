open Utils;
requireCSS("./welcomeNavBar.css");

module ToggleButton = {
  let component = ReasonReact.statelessComponent("ToggleButton");
  let make = ReasonReact.cloneElement(
    <button _type="button" className="navbar-toggle collapsed" />,
    ~props={"data-toggle":"collapse", "data-target":"#navbar-collapse", "aria-expanded":"false"},
    [|<span className="sr-only">{str("Toggle navigation")}</span>,
    <span className="icon-bar"></span>,
    <span className="icon-bar"></span>,
    <span className="icon-bar"></span> |]
  );
};

let component = ReasonReact.statelessComponent("WelcomeNavBar");

let make = _children => {
...component,
render: _self => {
  <nav className="navbar navbar-default navbar-fixed-top">
  <div className="contenido">
    <div className="navbar-header">
     {ToggleButton.make}
      <a className="page-scroll" href="#page-top">
          /* <apollo-navbar-logo></apollo-navbar-logo> */
      </a>
    </div>

    <div className="collapse navbar-collapse navbar-right navbar-main-collapse" id="navbar-collapse">
      <ul className="nav navbar-nav">
        <li className="hidden">
          <a href="#page-top"></a>
        </li>
        <li>
          <a className="page-scroll" href="#about">{str("Acerca de")}</a>
        </li>
        <li>
          <a className="page-scroll" href="#nosotros">{str("Nosotros")}</a>
        </li>
        <li>
          <a className="page-scroll" href="#contact">{str("Contacto")}</a>
        </li>
      </ul>
    </div>
  </div>
</nav>
}
};