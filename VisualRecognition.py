import io
import os

# Imports the Google Cloud client library
from google.cloud import vision
from google.cloud.vision import types

# Instantiates a client
client = vision.ImageAnnotatorClient()

# The name of the image file to annotate
file_name = os.path.abspath('resources/microfosil.jpg')

# Loads the image into memory
with io.open(microfosil.jpg, 'rb') as image_file:
    content = image_file.read()

image = types.Image(content=content)

# Performs label detection on the image file
response = client.label_detection(image=image)
labels = response.label_annotations

print('Labels:')
for label in labels:
    print(label.description)

with open('./microfosil.jpg', 'rb') as images_file:
    classes = visual_recognition.classify(
        images_file=images_file,
        threshold='0.6',
        owners=["me"]).get_result()
    print(json.dumps(classes, indent=2))



with open('./microfosil.jpg', 'rb') as images_file:
    classes = visual_recognition.classify(
        images_file=images_file,
        classifier_ids=["fosil"]).get_result()
    print(json.dumps(classes, indent=2))


def main(image_file):
    # Instantiates a client
    client = vision.ImageAnnotatorClient()

    # Loads the image into memory
    with io.open(image_file, 'rb') as image_file:
        content = image_file.read()

    image = types.Image(content=content)

    # Performs label detection on the image file
    response = client.visual_recognition(image=image)
    labels = response.visual_recognition

    print('Labels:')
    for label in labels:
        print(label.description)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('image_file', help='The image you\'d like to label.')
    args = parser.parse_args()
    main(args.image_file)

{
  "images": [
    {
      "classifiers": [
        {
          "classifier_id": "1758279329",
          "name": "fosil",
          "classes": [
            {
              "class": "cyanobacteria",
              "score": 0.7192
            },
            {
              "class": "Bacteria",
              "score": 0.7144
            },
            {
              "class": "Algae",
              "score": 0.7048
            },
            {
              "class": "Oscilatoriales",
              "score": 0.7035
            },
            {
              "class": "Prokaryote",
              "score": 0.7035
            },
            {
              "class": "Organism",
              "score": 0.49605
            },
            {
              "class": "Fossil",
              "score": 0.4517
            },
          ]
        }
      ],
      "image": "microfosil.jpg"
    }
  ],
  "images_processed": 1,
  "custom_classes": 6
}
