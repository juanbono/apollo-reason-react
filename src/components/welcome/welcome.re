open Utils;

open Reactstrap;

requireCSS("./welcome.css");

let fede = requireAssetURI("./img/federico.jpg");

let matias = requireAssetURI("./img/matias.jpg");

let juan = requireAssetURI("./img/juan.jpg");

let imgViajeros = requireAssetURI("./img/viajeros.jpg");

/* Introduccion data-spy="scroll" data-target=".navbar-fixed-top"*/
let component = ReasonReact.statelessComponent("Welcome");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <WelcomeNavBar />
      <div id="page-top">
        <header className="intro">
            <Container className="intro-body">
              <Row className="w-100">
                <div className="col-md-10 offset-md-1">
                  <h1 className="brand-heading"> (str("Apollo")) </h1>
                  <p className="pintro">
                    (
                      str({js| Comparte tu viaje con el mundo o inspírate |js})
                    )
                  </p>
                  <LoginButton />
                </div>
              </Row>
            </Container>
        </header>
        <Container id="about" className="content-section text-center">
          <Row>
            <div className="col-md-10 offset-md-1">
              <h2> (str("Acerca de Apollo")) </h2>
              <p>
                (
                  str(
                    {js| Apollo es una red social para compartir viajes. Te permite llevar a cabo la planificación de un viaje y el descubrimiento de nuevos destinos turísticos sin tener que pasar horas buscando información sobre el mismo en internet; tan solo debes entrar en la aplicación y ver los viajes y recomendaciones de otras personas que te alcanzarían para crear tu viaje ideal. |js}
                  )
                )
              </p>
              <p>
                (
                  str(
                    {js| A través de esta aplicación, se intenta resolver el problema de miles de personas que buscan realizar un viaje con éxito y con el menor esfuerzo posible, de la mano de viajeros que ya estuvieron en el lugar o quieren realizar la misma travesía. |js}
                  )
                )
              </p>
              <p>
                (
                  str(
                    {js| Apollo es un proyecto que comenzó en la catedra de Ingeniería de Software en la |js}
                  )
                )
                <a href="http://www.frd.utn.edu.ar"> (str("UTN FRD")) </a>
              </p>
            </div>
          </Row>
        </Container>
        <hr />
        /*Nosotros Section */
        <Container id="team" className="content-section text-center">
          <Row className="w-100">
            <div className="col-md-10 offset-md-1">
              <h2> ("Nosotros" |> str) </h2>
              <TeamIcon member=juan linkedin=Constants.linkedinJuan />
              <TeamIcon member=matias linkedin=Constants.linkedinMatias />
              <TeamIcon member=fede linkedin=Constants.linkedinFede />
            </div>
          </Row>
        </Container>
        <hr />
        /* Contacto Section */
        <Container id="contact" className="content-section text-center">
          <Row className="w-100">
            <div className="col-md-10 offset-md-1">
              <h2> ({js|Comunícate con Nosotros|js} |> str) </h2>
              <p> (str("Estamos en las redes sociales.")) </p>
              <ul className="list-inline banner-social-buttons">
                <li>
                  <a
                    href="https://www.facebook.com/pg/apollocom-238918739899778"
                    className="btn btn-default btn-lg">
                    <i className="fab fa-facebook-square" />
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
                  {js| Siéntete libre de escribirnos a nuestro email para poder seguir mejorando! |js}
                  |> str
                )
              </p>
              <p>
                <a href="mailto:feedback@apollo.com">
                  (str("feedback@apollo.com"))
                </a>
              </p>
            </div>
          </Row>
        </Container>
        /* Footer */
        <footer className="footer text-center">
            <p> ({js|Copyright © Apollo Corp. 2018|js} |> str) </p>
        </footer>
      </div>
    </div>
};