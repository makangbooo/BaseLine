from pymilvus import MilvusClient, DataType

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
    db_name="xjuspeech_xjrccb"
)


collections = client.list_collections()

client.drop_collection(
    collection_name="bank_doc_knowledge"
)