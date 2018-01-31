[@bs.module "./welcome-nav-bar"]
external reactClass : ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
/*requireCSS("./welcomeNavBar.css");

   module ToggleButton = {
       let component = ReasonReact.statelessComponent("ToggleButton");
       let make =
         ReasonReact.cloneElement(
           <button _type="button" className="navbar-toggle collapsed">
             <span className="sr-only"> (str("Toggle navigation")) </span>
             <span className="icon-bar" />
             <span className="icon-bar" />
             <span className="icon-bar" />
           </button>,
           ~props={
             "data-toggle": "collapse",
             "data-target": "#navbar-collapse",
             "aria-expanded": "false"
           },
           [||]
         );
     };

  let component = ReasonReact.statelessComponent("WelcomeNavBar");

  let make = _children => {
    ...component,
    render: _self =>
      <nav className="navbar navbar-default navbar-fixed-top">
        <div className="contenido">
          <div className="navbar-header">
            <button _type="button" className="navbar-toggle collapsed">
              <span className="sr-only"> (str("Toggle navigation")) </span>
              <span className="icon-bar" />
              <span className="icon-bar" />
              <span className="icon-bar" />
            </button>
            <a className="page-scroll" href="#page-top" />
          </div>
          <div
            className="collapse navbar-collapse navbar-right navbar-main-collapse"
            id="navbar-collapse">
            <ul className="nav navbar-nav">
              <li className="hidden"> <a href="#page-top" /> </li>
              <li>
                <a className="page-scroll" href="#about"> (str("Acerca de")) </a>
              </li>
              <li>
                <a className="page-scroll" href="#nosotros">
                  (str("Nosotros"))
                </a>
              </li>
              <li>
                <a className="page-scroll" href="#contact">
                  (str("Contacto"))
                </a>
              </li>
            </ul>
          </div>
        </div>
      </nav>
  };
  */