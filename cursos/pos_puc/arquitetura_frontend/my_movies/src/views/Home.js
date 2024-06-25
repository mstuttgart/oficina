import { MoviesServices } from "../api/MoviesServices";
import { MoviesContainer } from "../styles/MoviesContainer";
import { MoviesList } from "../components/MoviesList";
import { useState } from "react";
import { useEffect } from "react";

export const Home = () => {

  const [movies, setMovies] = useState([]);
  const fetchMovies = async () => {
    const { data } = await MoviesServices.getMovies();
    setMovies(data.results);
    console.log(data);
  };

  useEffect(() => {
    fetchMovies();
  }, []);

  return (
    <MoviesContainer>
      <MoviesList movies={movies} />
    </MoviesContainer>
  );
};
