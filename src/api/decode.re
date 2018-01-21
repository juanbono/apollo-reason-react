let travel: Js.Json.t => Models.travel =
  json =>
    Json.Decode.{
      title: json |> field("title", string),
      description: json |> field("description", string),
      image_public_url: json |> field("image_public_url", string),
      thumbnail_public_url: json |> field("thumbnail_public_url", string),
      publicx: json |> field("publicx", string),
      uuid: json |> field("uuid", int)
    };

let user: Js.Json.t => Models.user =
  json =>
    Json.Decode.{
      username: json |> field("username", string),
      email: json |> field("email", string),
      name: json |> field("name", string),
      lastname: json |> field("lastname", string),
      google_id: json |> field("google_id", string),
      gender: json |> field("gender", string),
      image_url: json |> field("image_url", string),
      image_public_url: json |> field("image_public_url", string),
      thumbnail_public_url: json |> field("thumbnail_public_url", string),
      description: json |> field("description", string),
      confirmed: json |> field("confirmed", bool),
      confirmed_at: json |> field("confirmed_at", string)
    };

let place: Js.Json.t => Models.place =
  json => {
    let coordDecoder = Json.Decode.pair(Json.Decode.float, Json.Decode.float);
    Json.Decode.{
      coordinates: json |> field("coordinates", coordDecoder), /* TODO: bug alert */
      title: json |> field("title", string),
      description: json |> field("description", string),
      travel_id: json |> field("travel_id", int)
    };
  };

let favorite: Js.Json.t => Models.favorite =
  json =>
    Json.Decode.{
      user_id: json |> field("user_id", int),
      travel_id: json |> field("travel_id", int)
    };

let event: Js.Json.t => Models.event =
  json =>
    Json.Decode.{
      event_type: json |> field("type", string), /* This field is named "type" on the backend */
      source_type: json |> field("source_type", string),
      source_id: json |> field("source_id", int),
      resource_type: json |> field("resource_type", string),
      resource_id: json |> field("resource_id", int)
    };

let comment: Js.Json.t => Models.comment =
  json =>
    Json.Decode.{
      content: json |> field("content", string),
      user_id: json |> field("user_id", int),
      travel_id: json |> field("travel_id", int)
    };

let authorization: Js.Json.t => Models.authorization =
  json =>
    Json.Decode.{
      user_id: json |> field("user_id", int),
      travel_id: json |> field("travel_id", int)
    };