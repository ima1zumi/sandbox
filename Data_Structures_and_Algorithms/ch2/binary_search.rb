def binary_search(array, search_value)
  # 探す値の上限と下限を決める。最初は下限が配列の先頭の値、上限は最後の値
  lower_bound = 0
  upper_bound = array.length - 1

  # 上限と下限の真ん中の値を調べ続けてループ
  while lower_bound <= upper_bound do
    # 上限と下限の真ん中の位置を見つける
    midpoint = (lower_bound + upper_bound) / 2

    # 真ん中の値を調べる
    value_at_midpoint = array[midpoint]

    # 真ん中の値が探している値ならOK
    # そうでないなら、探している値が真ん中の値より大きいか小さいかで場合分け
    if value_at_midpoint == search_value
      return midpoint
    elsif search_value < value_at_midpoint
      # 探している値が真ん中の値より小さい場合、上限を真ん中の位置の一つ前にする
      upper_bound = midpoint - 1
    else
      # 探している値が真ん中の値より大きい場合、下限を真ん中の位置の一つ後にする
      lower_bound = midpoint + 1
    end
  end

  # 見つからなかった場合はnilを返す
  return nil
end

p binary_search([3, 17, 75, 80, 202], 22) # => nil
