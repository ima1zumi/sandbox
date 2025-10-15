class Hello {
    public static void main(String[] args) {
        System.out.println("デバッグを開始します。");
        for (int i = 0; i < 3; i++) {
            int number = i * 10;
            int result = add(i, number);

            System.out.println("i =" + i + ", number = " + number + ", result = " + result);
        }
        System.out.println("デバッグを終了します。");
    }

    public static int add(int a, int b) {
        int sum = a + b;
        return sum;
    }
}
