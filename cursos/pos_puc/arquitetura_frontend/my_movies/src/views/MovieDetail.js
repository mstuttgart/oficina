import { useParams } from "react-router-dom";
import { useState } from "react";
import { useEffect } from "react";
import { MoviesServices } from "../api/MoviesServices";

export const MovieDetails = () => {
  const { id } = useParams();

  const [movie, setMovie] = useState({});
  const fetchMovie = async () => {
    const { data } = await MoviesServices.getMoviesById(id);
    setMovie(data);
    console.log(data);
  };

  useEffect(() => {
    fetchMovie();
  }, []);

  return (
    <>
      <h1>{movie.title}</h1>
      <article>{movie.overview}</article>
    </>
  );
};
