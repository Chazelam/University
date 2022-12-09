from tensorflow.keras.datasets import fashion_mnist
from tensorflow.python.keras.models import Sequential
from tensorflow.python.keras.layers import Dense
from tensorflow.python.keras.utils.np_utils import to_categorical
from tensorflow.python.keras.callbacks import TensorBoard


def main():
    (x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()

    x_train = x_train.reshape(60000, 784)
    x_train = x_train / 255
    x_test = x_test.reshape(10000, 784)
    x_test = x_test / 255
    y_train = to_categorical(y_train, 10)
    y_test = to_categorical(y_test, 10)

    model = Sequential()
    model.add(Dense(784, input_dim=784, activation="relu"))
    model.add(Dense(10, activation="softmax"))

    model.compile(loss="categorical_crossentropy", optimizer="SGD", metrics=["accuracy"])
    model.summary()
    callback = [TensorBoard(log_dir='logs', histogram_freq=1, write_images=True)]

    model.fit(x_train,
              y_train,
              batch_size=200,
              epochs=300,
              verbose=1,
              validation_split=0.2,
              callbacks=callback)

    model.save("fashion_model.h5")

    score = model.evaluate(x_test, y_test, verbose=1)
    print("Accuracy on test data is", score[1]*100, "percent")


if __name__ == "__main__":
    main()
