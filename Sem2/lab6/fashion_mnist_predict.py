from tensorflow.keras.datasets import fashion_mnist
from tensorflow.python.keras.models import load_model
from tensorflow.python.keras.utils.np_utils import to_categorical
import numpy
from PIL import Image

object_to_predict = numpy.random.randint(60000)


def main():
    (x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()

    pixels = x_train[object_to_predict]

    y_train = to_categorical(y_train, 10)
    x_train = x_train / 255

    classes = ["t-shirt", "trouser", "pullover", "dress", "coat", "sandal", "shirt", "sneaker", "bag", "ankle boot"]

    model = load_model("fashion_model.h5")

    image = Image.fromarray(pixels, "L")

    prediction = model.predict(numpy.reshape(x_train[object_to_predict], (1, 784)))

    print("Object",
          classes[numpy.argmax(y_train[object_to_predict])],
          "recognised as",
          classes[numpy.argmax(prediction)],
          "with accuracy",
          numpy.max(prediction*100),
          "percents")

    image.show()


if __name__ == "__main__":
    main()
