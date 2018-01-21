/*
  For more information, please see the official docs[1]
  [1]: https://developers.google.com/identity/sign-in/web/reference
 */
module AuthResponse = {
  /** The response returned when calling GoogleUser.getAuthResponse(includeAuthorizationData)
   or GoogleUser.reloadAuthResponse() methods.  */
  type t;
  /** The Access Token granted. */ [@bs.get]
  external getAccessToken : t => string = "access_token";
  /** The ID Token granted. */ [@bs.get]
  external getIdToken : t => string = "id_token";
  /** The scopes granted in the Access Token. */ [@bs.get]
  external getScope : t => string = "scope";
  /** The number of seconds until the Access Token expires. */ [@bs.get]
  external getExpiresIn : t => int = "expires_in";
  /**	The timestamp at which the user first granted the scopes requested. */
  [@bs.get]
  external getFirstIsuedAt : t => int = "first_issued_at";
  /** The timestamp at which the Access Token will expire. */ [@bs.get]
  external getExpiresAt : t => int = "expires_at";
};

module BasicProfile = {
  type t;
  [@bs.send] external getId : t => string = "getId";
  [@bs.send] external getEmail : t => string = "getEmail";
  [@bs.send] external getImageUrl : t => string = "getImageUrl";
  [@bs.send] external getName : t => string = "getName";
  [@bs.send] external getGivenName : t => string = "getGivenName";
  [@bs.send] external getFamilyName : t => string = "getFamilyName";
};

/** A GoogleUser object represents one user accoun */
type t;

/*LEEER https://developers.google.com/identity/sign-in/web/backend-auth */
/** Get the user's unique ID string.
 * Note: Do not use the Google IDs returned by getId() to communicate the currently signed in user to your backend server.
   Instead, send ID tokens, which can be securely validated on the server.  */
[@bs.send]
external getId : t => string = "getId";

/** Get the response object from the user's auth session. */ [@bs.send]
external getAuthResponse : t => AuthResponse.t = "getAuthResponse";

/** Get the user's basic profile information.
   * Note: Do not use the user's profile information to communicate the currently signed in user to
     your backend server. Instead, send ID tokens, which can be securely validated on the server.  */
[@bs.send]
external getBasicProfile : t => BasicProfile.t = "getBasicProfile";