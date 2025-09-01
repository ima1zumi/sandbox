def linear_search(array, search_value)
  # 配列の全要素をイテレーション
  array.each_with_index do | element, index |
    # 探す値が見つかったらインデックスを返す
    if element == search_value
      return index
    # 探す値より大きな要素に達したらループを抜ける
    elsif element > search_value
      break
    end
  end

  # 見つからなかった場合はnilを返す
  return nil
end

p linear_search([1, 3, 5, 7, 9], 7)  # => idx=3
