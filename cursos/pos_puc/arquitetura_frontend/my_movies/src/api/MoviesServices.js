import axios from "axios";
const API_KEY = "025c0ed662b58ffdc4947d077645d46b";
const BASE_URL = "https://api.themoviedb.org/3/";
const withBaseUrl = (path) => `${BASE_URL}${path}?api_key=${API_KEY}`;

export class MoviesServices {
  static getMovies() {
    return axios(withBaseUrl("movie/popular"));
  }

  static getMoviesById(id){
    return axios(withBaseUrl(`movie/${id}`))

  }
}
