import json
import argparse
import io
from ibm_watson import VisualRecognitionV3
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator

authenticator = IAMAuthenticator('{api-key}')
visual_recognition = VisualRecognitionV3(
    version='2018-03-19',
    authenticator=authenticator
)

with open('./microfosil.jpg', 'rb') as images_file:
    classes = visual_recognition.classify(
        images_file=images_file,
        threshold='0.6',
        owners=["me"]).get_result()
    print(json.dumps(classes, indent=2))



with open('./microfosil.jpg', 'rb') as images_file:
    classes = visual_recognition.classify(
        images_file=images_file,
        classifier_ids=["food"]).get_result()
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
