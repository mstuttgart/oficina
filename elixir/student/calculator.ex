defmodule Calculator do
    @moduledoc """
    Define a Calculator module and functions to execute it.
    """

    @doc """
    Start the system to process some result.
    """
    def start() do
    joao = %Student{name: "João Joaquim", results: build_subjects([5.2, 3.9, 2.7, 9.8])}
    maria = %Student{name: "Maria da Silva", results: build_subjects([8.4, 7.5, 9.4, 2.8])}
    pedro = %Student{name: "Pedro Pedrada", results: build_subjects([5.4, 4.9, 2.2, 3.8])}
    kaua = %Student{name: "Kauã Camboinhas", results: build_subjects([5.4, 4.9, 2.2, 3.8])}

    result = calculate([joao, maria, pedro, kaua])
    best = best_result(result)

    {result, best}
    end

    @doc """
    Get all students with their averages.

    ## Parameters

    - `students` - A list of Student structs.
    """
    defp calculate(students) do
        students
        |> Enum.map(&(
            %{
                first_name: Student.first_name(&1),
                last_name: Student.last_name(&1),
                average: average(&1)
            }
        ))
    end

    @doc """
    Calculate the average of a Student.

    ## Parameters

    - `student` - A Student struct.
    """
    defp average(student) do
        total = Enum.count(student.results) 

        result = student.results
        |> Enum.map(&(&1.result))
        |> Enum.reduce(&(&1 + &2))

        Float.ceil(result / total, 2)
    end

    @doc """
    Get tge greater average.

    ## Parameters

    - `students` - A list of students with their averages
    """
    defp best_result(students) do
        best = students
        |> Enum.map(&(&1.average))
        |> Enum.max

        students
        |> Enum.filter(&(&1.average === best))
    end

    @doc """
    Build some subjects and some random results.

    ## Parameters

    - `results` - A list of results
    """
    defp build_subjects(results) do
        subjects = ["Matemática", "Português", "Geografia", "História"]

        subjects
        |> Enum.map(&(%Subject{name: &1, result: Enum.random(results)}))
    end
end