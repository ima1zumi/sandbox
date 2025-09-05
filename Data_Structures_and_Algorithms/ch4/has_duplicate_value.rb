def has_duplicate_value(array)
  for i in 0..array.size
    for j in 0..array.size
      if i != j && array[i] == array[j]
        return true
      end
    end
  end
  return false
end

pp has_duplicate_value([1, 2])

