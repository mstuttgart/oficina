defmodule App.CalculatorTest do
  use ExUnit.Case, async: true

  @moduletag :math

  setup do
    {:ok, michell: 2, davi: 6}
  end

  test "should return 4 when multiply 2 by 2", %{michell: valor} do
    assert App.Calculator.multiply(2, valor) == 4
  end

  test "should return 6 when multiply 2 by 3" do
    assert App.Calculator.multiply(2, 3) == 6
  end

  @tag :negative
  test "should return nil when multiply 2 by nil" do
    assert App.Calculator.multiply(nil, 2) == nil
  end

  test "shouldn't return 10 when multiply 2 by 4" do
    refute App.Calculator.multiply(2, 4) == 10, "This is an error!!"
  end
end
