let travel: Models.travel => Js.Json.t =
  travelObj =>
    Json.Encode.(
      object_([
        ("title", string(travelObj.title)),
        ("description", string(travelObj.description)),
        ("image_public_url", string(travelObj.image_public_url)),
        ("thumbnail_public_url", string(travelObj.thumbnail_public_url)),
        ("publicx", string(travelObj.publicx)),
        ("uuid", int(travelObj.uuid))
      ])
    );

let user: Models.user => Js.Json.t =
  userObj =>
    Json.Encode.(
      object_([
        ("username", string(userObj.username)),
        ("email", string(userObj.email)),
        ("name", string(userObj.name)),
        ("lastname", string(userObj.lastname)),
        ("google_id", string(userObj.google_id)),
        ("gender", string(userObj.gender)),
        ("image_url", string(userObj.image_url)),
        ("image_public_url", string(userObj.image_public_url)),
        ("thumbnail_public_url", string(userObj.thumbnail_public_url)),
        ("description", string(userObj.description)),
        ("confirmed", bool(userObj.confirmed)),
        ("confirmed_at", string(userObj.confirmed_at))
      ])
    );

let place: Models.place => Js.Json.t =
  placeObj =>
    Json.Encode.(
      object_
        /* ("coordinates", Json.Encode.) */
        ([
          ("title", string(placeObj.title)),
          ("description", string(placeObj.description)),
          ("travel_id", int(placeObj.travel_id))
        ])
    );

let favorite: Models.favorite => Js.Json.t =
  favObj =>
    Json.Encode.(
      object_([
        ("user_id", int(favObj.user_id)),
        ("travel_id", int(favObj.travel_id))
      ])
    );

let event: Models.event => Js.Json.t =
  eventObj =>
    Json.Encode.(
      object_([
        (
          "type",
          string(eventObj.event_type)
        ), /* This field is named "type" on the backend */
        ("source_type", string(eventObj.source_type)),
        ("source_id", int(eventObj.source_id)),
        ("resource_type", string(eventObj.resource_type)),
        ("resource_id", int(eventObj.resource_id))
      ])
    );

let comment: Models.comment => Js.Json.t =
  commentObj =>
    Json.Encode.(
      object_([
        ("content", string(commentObj.content)),
        ("user_id", int(commentObj.user_id)),
        ("travel_id", int(commentObj.travel_id))
      ])
    );

let authorization: Models.authorization => Js.Json.t =
  authObj =>
    Json.Encode.(
      object_([
        ("user_id", int(authObj.user_id)),
        ("travel_id", int(authObj.travel_id))
      ])
    );

let formData: Val.SignUpFormParams.state => Js.Json.t =
  obj =>
    Json.Encode.(
      object_([
        ("username", string(obj.username)),
        ("name", string(obj.firstname)),
        ("lastname", string(obj.lastname)),
        ("description", string(obj.description))
      ])
    );