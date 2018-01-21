type travel = {
  title: string,
  description: string,
  image_public_url: string,
  thumbnail_public_url: string,
  publicx: string,
  uuid: int
};

type user = {
  username: string,
  email: string,
  name: string,
  lastname: string,
  google_id: string,
  gender: string,
  image_url: string,
  image_public_url: string,
  thumbnail_public_url: string,
  description: string,
  confirmed: bool,
  confirmed_at: string
};

type place = {
  coordinates: (float, float), /* TODO */
  title: string,
  description: string,
  travel_id: int
};

type favorite = {
  user_id: int,
  travel_id: int
};

type event = {
  event_type: string, /* This field is named "type" on the backend */
  source_type: string,
  source_id: int,
  resource_type: string,
  resource_id: int
};

type comment = {
  content: string,
  user_id: int,
  travel_id: int
};

type authorization = {
  user_id: int,
  travel_id: int
};