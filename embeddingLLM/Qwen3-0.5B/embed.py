import requests
import json
import sys

EMBEDDING_SERVICE_URL = "http://1.95.55.32:35007/embed"

def vectorize(text):
    try:
        # 构造JSON请求体
        payload = {"text": text}
        headers = {"Content-Type": "application/json"}
        
        # 发送POST请求
        response = requests.post(
            EMBEDDING_SERVICE_URL, 
            data=json.dumps(payload), 
            headers=headers
        )
        
        # 检查响应状态
        if response.status_code != 200:
            raise RuntimeError(f"Request failed with status: {response.status_code}")
        
        # 解析JSON响应
        response_data = response.json()
        embedding_list = response_data.get("embedding")
        
        if not isinstance(embedding_list, list):
            raise ValueError("Unexpected embedding format")
        
        # 将列表元素转为float类型
        vector = [float(val) for val in embedding_list]
        return vector
        
    except Exception as e:
        raise RuntimeError(f"Embedding service error: {str(e)}")

if __name__ == "__main__":
    try:
        # 从控制台获取输入
        text = input("请输入文本: ").strip()
        if not text:
            print("错误：输入不能为空")
            sys.exit(1)
            
        # 获取并打印向量
        vector = vectorize(text)
        print("文本向量结果:")
        print(vector)
        print(f"向量维度: {len(vector)}")
        
    except Exception as e:
        print(f"发生错误: {str(e)}")
        sys.exit(1)