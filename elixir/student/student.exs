defmodule Student do
  @moduledoc """
  Define a Student struct and function to handle a student
  """
  defstruct name: nil, results: []

  @doc """
  Get the first name of Student.

  ## Parameters

  - `student` - A Student struct.

  ## Examples
  
  * joao = %Student{name: "João Joaquim"}
  * Student.first_name(joao)
  * "João"
  """
  def first_name(student) do
    student.name
    |> String.split()
    |> List.first()
  end

  @doc """
  Get the last name of a Student.

  ## Parameters

  - `student` - A Student struct.

  ## Examples

  * joao = %Student{name: "Joao Joaquim"}
  * Student.last_name(joao)
  * "Joaquim"
  """
  def last_name(student) do
    student.name
    |> String.split()
    |> List.last()
  end

end