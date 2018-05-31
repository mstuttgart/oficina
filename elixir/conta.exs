defmodule Contador do
    def contar([]), do: 0
    def contar([head | tail]), do: 1 + contar(tail)
end