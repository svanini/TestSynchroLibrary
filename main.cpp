#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <fstream>
#include <iostream>
#include <QDebug>
#include "synchrolibrary.h"
#include <QFile>

int main(int argc, char *argv[])
{
    /*******************
     * write_sync_json *
     *******************/
 /*   QJsonDocument doc{QJsonDocument::fromJson(R"({
        "id" : "sample1",
        "document" : {
                  "value" : 13,
                  "dbInfo" : {
                        "value" : "hello"
                  },
                  "other" : [{
                               "id" : "sample2",
                               "alpha" : {
                                "beta" : "gamma"
                               }
                             },
                             {
                              "id" : "sample3",
                              "alpha2" : {
                               "beta2" : "gamma2"
                              }
                             }]
                }})")};

    std::filebuf fb;
    fb.open("doc.ac2.flat.testsynchrolib.json", std::ios::out);
    std::ostream os(&fb);
    QMap<QString, QVariant> app_settings;
    app_settings.insert("instance_id", "root-{deab8ffe-81c5-4909-9233-ce489a88026f}_install_doc.ac2");
    app_settings.insert("name", "doc.ac2");
    app_settings.insert("owner", "testapi");
    app_settings.insert("description", "doc.ac2");
    app_settings.insert("uniqueid_keys", "_id,document.dbInfo.uuid,dbInfo.uuid,id,name,type");
    QString error;
    write_sync_json(doc.object(), os, app_settings, &error);
    fb.close();
    if (error.isEmpty())
        qDebug() << "doc.ac2.flat.testsynchrolib.json succesfully written";
    else
        qDebug() << "Error when calling write sync json:" << error;
*/
    /******************
     * read_sync_json *
     ******************/
    /*QJsonDocument doc{QJsonDocument::fromJson(R"({
        "changes": [
          {
              "changes": [
                  {
                      "rev": "1-2bf527e7c5fd80fe992986d912007309fb0fbf6c0bf48837720d50eb42c23768"
                  }
              ],
              "id": "root-sample1",
              "seq": "1",
              "type": "create"
          },
          {
              "changes": [
                  {
                      "rev": "1-8b6d44dd73b7940ef6b8c0498f388ff57225594f88c5889474491d91762e1a21"
                  }
              ],
              "id": "f55939cfb4dde5cfc1d7722de9a08556a2349627",
              "seq": "2",
              "type": "create"
          },
          {
              "changes": [
                  {
                      "rev": "1-d04bc4370a873494f6a4b0df9db5db6d400119579d9c680c934465e9db6ad25b"
                  }
              ],
              "id": "6ed3ff371fc19ad6e15ac5a75cfded61cc892139",
              "seq": "3",
              "type": "create"
          },
          {
              "changes": [
                  {
                      "rev": "1-02cf173e3b9e2378caf467d1bf702839a3336d66f3daba43ff0b2eb7e1f63b27"
                  }
              ],
              "id": "root-537cdd666cd9f0ed808f62b54b032974705d4b3e",
              "seq": "4",
              "type": "create"
          }
        ],
        "default": {
          "6ed3ff371fc19ad6e15ac5a75cfded61cc892139": {
              "history": {
              },
              "id": "6ed3ff371fc19ad6e15ac5a75cfded61cc892139",
              "revisions": {
                  "1-d04bc4370a873494f6a4b0df9db5db6d400119579d9c680c934465e9db6ad25b": {
                      "##flat_domain": "d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                      "_id": "6ed3ff371fc19ad6e15ac5a75cfded61cc892139",
                      "_rev": "1-d04bc4370a873494f6a4b0df9db5db6d400119579d9c680c934465e9db6ad25b",
                      "alpha2": {
                          "beta2": "gamma2"
                      },
                      "id": "sample3"
                  }
              }
          },
          "f55939cfb4dde5cfc1d7722de9a08556a2349627": {
              "history": {
              },
              "id": "f55939cfb4dde5cfc1d7722de9a08556a2349627",
              "revisions": {
                  "1-8b6d44dd73b7940ef6b8c0498f388ff57225594f88c5889474491d91762e1a21": {
                      "##flat_domain": "d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                      "_id": "f55939cfb4dde5cfc1d7722de9a08556a2349627",
                      "_rev": "1-8b6d44dd73b7940ef6b8c0498f388ff57225594f88c5889474491d91762e1a21",
                      "alpha": {
                          "beta": "gamma"
                      },
                      "id": "sample2"
                  }
              }
          },
          "root-537cdd666cd9f0ed808f62b54b032974705d4b3e": {
              "history": {
              },
              "id": "root-537cdd666cd9f0ed808f62b54b032974705d4b3e",
              "revisions": {
                  "1-02cf173e3b9e2378caf467d1bf702839a3336d66f3daba43ff0b2eb7e1f63b27": {
                      "##flat_domain": "d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                      "##flat_node": "root-{deab8ffe-81c5-4909-9233-ce489a88026f}_install_doc.ac2",
                      "##flat_ordering": [
                          "f55939cfb4dde5cfc1d7722de9a08556a2349627",
                          "6ed3ff371fc19ad6e15ac5a75cfded61cc892139"
                      ],
                      "_id": "root-537cdd666cd9f0ed808f62b54b032974705d4b3e",
                      "_rev": "1-02cf173e3b9e2378caf467d1bf702839a3336d66f3daba43ff0b2eb7e1f63b27"
                  }
              }
          },
          "root-sample1": {
              "history": {
              },
              "id": "root-sample1",
              "revisions": {
                  "1-2bf527e7c5fd80fe992986d912007309fb0fbf6c0bf48837720d50eb42c23768": {
                      "_id": "root-sample1",
                      "_rev": "1-2bf527e7c5fd80fe992986d912007309fb0fbf6c0bf48837720d50eb42c23768",
                      "document": {
                          "dbInfo": {
                              "value": "hello"
                          },
                          "other": "##flat_reference:d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                          "value": 13
                      },
                      "id": "sample1"
                  }
              }
          }
        },
        "description": "doc.ac2",
        "hash": "5f59d76d1577d3070add8c31cd677c3fa3bf3a100fe335f0f0f835c599455936",
        "local": {
          "description": {
              "history": {
              },
              "id": "description",
              "revisions": {
                  "1-73da3afd84afe7988026342fdea96dd9342d8c11d5a10af20900a68bf6b5fd24": {
                      "_id": "description",
                      "_rev": "1-73da3afd84afe7988026342fdea96dd9342d8c11d5a10af20900a68bf6b5fd24",
                      "value": "doc.ac2"
                  }
              }
          },
          "owner": {
              "history": {
              },
              "id": "owner",
              "revisions": {
                  "1-e47debf7cedd50a73f3100f65b73aa6aeb19d638c0aeda7bc248e5d63e6dc6a7": {
                      "_id": "owner",
                      "_rev": "1-e47debf7cedd50a73f3100f65b73aa6aeb19d638c0aeda7bc248e5d63e6dc6a7",
                      "value": "testapi"
                  }
              }
          }
        },
        "owner": "testapi",
        "source_hash": "",
        "update_seq": 4
        })")};
    //write json to file
    QFile json_file("doc.ac2.syncjson.json");
    json_file.open(QFile::WriteOnly);
    json_file.write(doc.toJson());
    json_file.close();
    //read inputstream of previously written file
    std::ifstream is ("doc.ac2.syncjson.json", std::ifstream::in);
    if (is) {
        QMap<QString, QVariant> settings;
        settings.insert("instance_id", "root-{deab8ffe-81c5-4909-9233-ce489a88026f}_install_doc.ac2");
        settings.insert("name", "doc.ac2");
        settings.insert("owner", "testapi");
        settings.insert("description", "doc.ac2");
        QString error;
        QJsonObject json_obj = read_sync_json(is, settings, &error);
        if (json_obj.isEmpty()) {
            qDebug() << "Got an error during read sync json:" << error;
            return 0;
        }
        QStringList keys = json_obj.keys();
        if (!(keys.contains("_sync_result") && keys.contains("document") && keys.contains("id"))) {
            qDebug() << "Keys _sync_result, document and id are not contained";
            return 0;
        }
        if (json_obj.value("id") != "sample1") {
            qDebug() << "The value of key \"id\" does not match";
            return 0;
        }
        qDebug() << "Sync JSON succesfully read";
        is.close();
    }*/
    /******************
     *      merge     *
     ******************/
    QJsonDocument doc{QJsonDocument::fromJson(R"({
        "id" : "sample1",
        "document" : {
                  "value" : 13,
                  "dbInfo" : {
                        "value" : "hello"
                  },
                  "other" : [{
                               "id" : "sample2",
                               "alpha" : {
                                "beta" : "gamma"
                               }
                             },
                             {
                              "id" : "sample3",
                              "alpha2" : {
                               "beta2" : "gamma2"
                              }
                             }]
                }})")};

    QJsonDocument syn_dump{QJsonDocument::fromJson(R"({
        "changes": [
          {
              "changes": [
                  {
                      "rev": "1-2bf527e7c5fd80fe992986d912007309fb0fbf6c0bf48837720d50eb42c23768"
                  }
              ],
              "id": "root-sample1",
              "seq": "1",
              "type": "create"
          },
          {
              "changes": [
                  {
                      "rev": "1-8b6d44dd73b7940ef6b8c0498f388ff57225594f88c5889474491d91762e1a21"
                  }
              ],
              "id": "f55939cfb4dde5cfc1d7722de9a08556a2349627",
              "seq": "2",
              "type": "create"
          },
          {
              "changes": [
                  {
                      "rev": "1-d04bc4370a873494f6a4b0df9db5db6d400119579d9c680c934465e9db6ad25b"
                  }
              ],
              "id": "6ed3ff371fc19ad6e15ac5a75cfded61cc892139",
              "seq": "3",
              "type": "create"
          },
          {
              "changes": [
                  {
                      "rev": "1-02cf173e3b9e2378caf467d1bf702839a3336d66f3daba43ff0b2eb7e1f63b27"
                  }
              ],
              "id": "root-537cdd666cd9f0ed808f62b54b032974705d4b3e",
              "seq": "4",
              "type": "create"
          }
        ],
        "default": {
          "6ed3ff371fc19ad6e15ac5a75cfded61cc892139": {
              "history": {
              },
              "id": "6ed3ff371fc19ad6e15ac5a75cfded61cc892139",
              "revisions": {
                  "1-d04bc4370a873494f6a4b0df9db5db6d400119579d9c680c934465e9db6ad25b": {
                      "##flat_domain": "d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                      "_id": "6ed3ff371fc19ad6e15ac5a75cfded61cc892139",
                      "_rev": "1-d04bc4370a873494f6a4b0df9db5db6d400119579d9c680c934465e9db6ad25b",
                      "alpha2": {
                          "beta2": "gamma2"
                      },
                      "id": "sample3"
                  }
              }
          },
          "f55939cfb4dde5cfc1d7722de9a08556a2349627": {
              "history": {
              },
              "id": "f55939cfb4dde5cfc1d7722de9a08556a2349627",
              "revisions": {
                  "1-8b6d44dd73b7940ef6b8c0498f388ff57225594f88c5889474491d91762e1a21": {
                      "##flat_domain": "d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                      "_id": "f55939cfb4dde5cfc1d7722de9a08556a2349627",
                      "_rev": "1-8b6d44dd73b7940ef6b8c0498f388ff57225594f88c5889474491d91762e1a21",
                      "alpha": {
                          "beta": "gamma"
                      },
                      "id": "sample2"
                  }
              }
          },
          "root-537cdd666cd9f0ed808f62b54b032974705d4b3e": {
              "history": {
              },
              "id": "root-537cdd666cd9f0ed808f62b54b032974705d4b3e",
              "revisions": {
                  "1-02cf173e3b9e2378caf467d1bf702839a3336d66f3daba43ff0b2eb7e1f63b27": {
                      "##flat_domain": "d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                      "##flat_node": "root-{deab8ffe-81c5-4909-9233-ce489a88026f}_install_doc.ac2",
                      "##flat_ordering": [
                          "f55939cfb4dde5cfc1d7722de9a08556a2349627",
                          "6ed3ff371fc19ad6e15ac5a75cfded61cc892139"
                      ],
                      "_id": "root-537cdd666cd9f0ed808f62b54b032974705d4b3e",
                      "_rev": "1-02cf173e3b9e2378caf467d1bf702839a3336d66f3daba43ff0b2eb7e1f63b27"
                  }
              }
          },
          "root-sample1": {
              "history": {
              },
              "id": "root-sample1",
              "revisions": {
                  "1-2bf527e7c5fd80fe992986d912007309fb0fbf6c0bf48837720d50eb42c23768": {
                      "_id": "root-sample1",
                      "_rev": "1-2bf527e7c5fd80fe992986d912007309fb0fbf6c0bf48837720d50eb42c23768",
                      "document": {
                          "dbInfo": {
                              "value": "hello"
                          },
                          "other": "##flat_reference:d5ce4abe7a3b322c6ac624ff7e7e7cd8f00c1b9b",
                          "value": 13
                      },
                      "id": "sample1"
                  }
              }
          }
        },
        "description": "doc.ac2",
        "hash": "5f59d76d1577d3070add8c31cd677c3fa3bf3a100fe335f0f0f835c599455936",
        "local": {
          "description": {
              "history": {
              },
              "id": "description",
              "revisions": {
                  "1-73da3afd84afe7988026342fdea96dd9342d8c11d5a10af20900a68bf6b5fd24": {
                      "_id": "description",
                      "_rev": "1-73da3afd84afe7988026342fdea96dd9342d8c11d5a10af20900a68bf6b5fd24",
                      "value": "doc.ac2"
                  }
              }
          },
          "owner": {
              "history": {
              },
              "id": "owner",
              "revisions": {
                  "1-e47debf7cedd50a73f3100f65b73aa6aeb19d638c0aeda7bc248e5d63e6dc6a7": {
                      "_id": "owner",
                      "_rev": "1-e47debf7cedd50a73f3100f65b73aa6aeb19d638c0aeda7bc248e5d63e6dc6a7",
                      "value": "testapi"
                  }
              }
          }
        },
        "owner": "testapi",
        "source_hash": "",
        "update_seq": 4
        })")};
    QFile json_file("doc.ac2.syncdump.json");
    json_file.open(QFile::WriteOnly);
    json_file.write(syn_dump.toJson());
    json_file.close();
    //read inputstream of previously written file
    std::ifstream is ("doc.ac2.syncdump.json", std::ifstream::in);
    if (is) {
        QMap<QString, QVariant> settings;
        settings.insert("instance_id", "root-{deab8ffe-81c5-4909-9233-ce489a88026f}_install_doc.ac2");
        settings.insert("name", "doc.ac2");
        settings.insert("owner", "testapi");
        settings.insert("description", "doc.ac2");
        settings.insert("uniqueid_keys", "_id,document.dbInfo.uuid,dbInfo.uuid,id,name,type");
        QString error;
        QJsonObject json_obj = merge(doc.object(), is, settings, &error);
        if (json_obj.isEmpty()) {
            qDebug() << "Got an error during read sync json:" << error;
            return 0;
        }
        if (!(json_obj.contains("document"))) {
            qDebug() << "Keys _sync_result, document is not contained";
            return 0;
        }
        if (!json_obj.value("document").toObject().contains("dbInfo")) {
            qDebug() << "Keys _sync_result, document.dbInfo is not contained";
            return 0;
        }
        if (!json_obj.value("document").toObject().value("dbInfo").toObject().contains("syncdata")) {
            qDebug() << "Keys _sync_result, document.dbInfo.syncdata is not contained";
            return 0;
        }
        QJsonObject syncdata = json_obj.value("document").toObject().value("dbInfo").toObject().value("syncdata").toObject();

        if (!syncdata.contains("6ed3ff371fc19ad6e15ac5a75cfded61cc892139")) {
            qDebug() << "value 6ed3ff371fc19ad6e15ac5a75cfded61cc892139 is not contained";
            return 0;
        }
        if(!syncdata.contains("root-sample1")) {
            qDebug() << "value root-sample1 is not contained";
            return 0;
        }
        if(!json_obj.value("document").toObject().contains("other")) {
            qDebug() << "value other is not contained";
            return 0;
        }
        QJsonArray array = json_obj.value("document").toObject().value("other").toArray();
        if (array.size() != 2) {
            qDebug() << "Array size is not 2";
            return 0;
        }
        if(array.at(0).toObject().value("id").toString() != "sample2") {
            qDebug() << "id(0) value is not sample 2";
            return 0;
        }
        if(array.at(1).toObject().value("id").toString() != "sample3") {
            qDebug() << "id(1) value is not sample 3";
            return 0;
        }
        if(json_obj.value("document").toObject().value("value").toInt() != 13) {
            qDebug() << "document.value is not 13";
            return 0;
        }

        is.close();
    } else {
        qDebug() << "unable to open input stream of syncdump.json file";
    }
    qDebug() << "Call to merge successfully executed";

    return 0;
}
