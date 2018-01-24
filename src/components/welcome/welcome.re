open Utils;

requireCSS("./welcome.css");

/* Introduccion data-spy="scroll" data-target=".navbar-fixed-top"*/
let component = ReasonReact.statelessComponent("Welcome");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <WelcomeNavBar />
      <div id="page-top">
        <header className="intro">
          <div className="intro-body">
            <div className="container">
              <div className="row">
                <div className="col-md-10 col-md-offset-1">
                  <h1 className="brand-heading"> (str("Apollo")) </h1>
                  <p className="pintro">
                    (str("Comparte tu viaje con el mundo o insp\195\173rate"))
                  </p>
                  <LoginButton />
                  <div>
                    <a href="#about" className="btn btn-circle page-scroll">
                      <i className="fa fa-angle-double-down animated" />
                    </a>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </header>
        <section id="about" className="container content-section text-center">
          <div className="row">
            <div className="col-md-10 col-md-offset-1">
              <h2> (str("Acerca de Apollo")) </h2>
              <p>
                (
                  str(
                    "Apollo es una red social para compartir viajes. Te permite llevar a cabo la planificaci\195\179n de un viaje y el descubrimiento de nuevos destinos tur\195\173sticos sin tener que pasar horas buscando informaci\195\179n sobre el mismo en internet; tan solo debes entrar en la aplicaci\195\179n y ver los viajes y recomendaciones de otras personas que te alcanzar\195\161n para crear tu viaje ideal."
                  )
                )
              </p>
              <p>
                (
                  str(
                    "A trav\195\169s de esta aplicaci\195\179n, se intenta resolver el problema de miles de personas que buscan realizar un viaje con \195\169xito y con el menor esfuerzo posible, de la mano de viajeros que ya estuvieron en el lugar o quieren realizar la misma traves\195\173a."
                  )
                )
              </p>
              <p>
                (
                  str(
                    "Apollo es un proyecto que comenz\195\179 en la catedra de Ingenier\195\173a de Software en la"
                  )
                )
                <a href="http://www.frd.utn.edu.ar"> (str("UTN FRD")) </a>
              </p>
            </div>
          </div>
        </section>
        /*Nosotros Section */
        <section
          id="nosotros" className="container content-section text-center">
          <div className="row">
            <h2> ("Nosotros" |> str) </h2>
            <div className="equipo">
              <a href="https://ar.linkedin.com/in/juan-bono-62803685">
                <img className="equipo-img" src="assets/img/equipo/juan.jpg" />
              </a>
            </div>
            <div className="equipo">
              <a
                href="https://ar.linkedin.com/in/mat\195\173as-mangiantini-668001126">
                <img
                  className="equipo-img"
                  src="assets/img/equipo/matias.jpg"
                />
              </a>
            </div>
            <div className="equipo">
              <a href="https://ar.linkedin.com/in/federico-sanches">
                <img
                  className="equipo-img"
                  src="assets/img/equipo/federico.jpg"
                />
              </a>
            </div>
          </div>
        </section>
        /* Contacto Section */
        <section
          id="contact" className="container content-section text-center">
          <div className="row">
            <div className="col-md-10 col-md-offset-1">
              <h2> (str("Comun\195\173cate con Nosotros")) </h2>
              <p> (str("Estamos en las redes sociales.")) </p>
              <ul className="list-inline banner-social-buttons">
                <li>
                  <a
                    href="https://www.facebook.com/pg/apollocom-238918739899778"
                    className="btn btn-default btn-lg">
                    <i className="fa fa-facebook fa-fw" />
                    <span className="network-name"> ("Facebook" |> str) </span>
                  </a>
                </li>
                <li>
                  <a href="#" className="btn btn-default btn-lg">
                    <i className="fa fa-twitter fa-fw" />
                    <span className="network-name"> ("Twitter" |> str) </span>
                  </a>
                </li>
                <li>
                  <a
                    href="https://github.com/apollo-utn-frd/apollo"
                    className="btn btn-default btn-lg">
                    <i className="fa fa-github fa-fw" />
                    <span className="network-name"> ("Github" |> str) </span>
                  </a>
                </li>
              </ul>
              <p>
                (
                  "\194\161Si\195\169ntete libre de escribirnos a nuestro email para poder seguir mejorando!"
                  |> str
                )
              </p>
              <p>
                <a href="mailto:feedback@apollo.com">
                  (str("feedback@apollo.com"))
                </a>
              </p>
            </div>
          </div>
        </section>
        /* Footer */
        <footer>
          <div className="container text-center">
            <p> ("Copyright &copy; Apollo Corp. 2016" |> str) </p>
          </div>
        </footer>
      </div>
    </div>
};